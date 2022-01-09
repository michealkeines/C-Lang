#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define MAX_DATA 512
#define MAX_ROWS 100

struct Address {
	int id;
	int set;
	char name[MAX_DATA];
	char email[MAX_DATA];
};

struct Database {
	struct Address rows[MAX_ROWS];
};

struct Connection {
	FILE * file;
	struct Database * db;
};


void die(const char * message, struct Connection * conn) {
	if (errno) {
		perror(message);
	} else {
		printf("Error: %s\n", message);
	}
	if (conn != NULL) {
		Database_close(conn);
	}
	exit(1);
}

void Address_print(struct Address * addr) {
	printf("%d %s %s\n", addr->id, addr->name, addr->email);
}

void Database_load(struct Connection * conn) {
	// Reads from conn->file and writes to conn->db
	int rc = fread(conn->db, sizeof(struct Database), 1, conn->file);
	
	if (rc != 1) {
		die("Failed to load Database.", conn);
	}
}

struct Connection * Database_open(const char * filename, char mode) {
	struct Connection * conn = malloc(sizeof(struct Connection));
	
	if (!conn) {
		die("Memory error", conn);
	}

	conn->db = malloc(sizeof(struct Database));

	if (!conn->db) {
		die("Memory error", conn);
	}

	if (mode == 'c') {
		conn->file = fopen(filename, "w");
	} else {
		conn->file = fopen(filename, "r+");

		if (conn->file) {
			Database_load(conn);
		}
	}

	if (!conn->file) {
		die("Failed to open the file.", conn);
	}

	return conn;
}

void Database_close(struct Connection * conn) {
	if (conn) {
		if (conn->file) {
			fclose(conn->file);
		}
		if (conn->db) {
			free(conn->db);
			free(conn);
		}
	}
}

void Database_write(struct Connection * conn) {
	// rewind(file *) to get the file pointer back to the beginning of the stream, it is usefull if you have to use stream many times
	rewind(conn->file);

	int rc = fwrite(conn->db, sizeof(struct Database), 1, conn->file);
	
	if (rc != 1) {
		die("Failed to write to Database.", conn);
	}

	rc = fflush(conn->file);

	if (rc == -1) {
		die("Cannot flush Database.", conn);
	}
}

void Database_create(struct Connection * conn) {
	int i = 0;
	for (i=0; i < MAX_ROWS; i++) {
		struct Address addr = {.id = i, .set = 0};

		conn->db->rows[i] = addr;
	}
}

void Database_set(struct Connection * conn, int id, const char * name, const char * email) {
	struct Address * addr = &conn->db->rows[id];
	if (addr->set) {
		die("Already set, delete it first", conn);
	}

	addr->set = 1;
	// stncpy will copy the whole 512 byte, thus the buff wont be null terminated, we add MAX_DATA - 1, to stop that from happening, as the last byte will automatically padded with \0
	char * res = strncpy(addr->name, name, MAX_DATA - 1);

	if (!res) {
		die("Name copy failed",conn);
	}

	res = strncpy(addr->email, email, MAX_DATA - 1);

	if (!res) {
		die("Email copy failed",conn);
	}
}


void Database_get(struct Connection * conn, int id) {
	struct Address * addr = &conn->db->rows[id];

	if (addr->set) {
		Address_print(addr);
	} else {
		die("ID is not set", conn);
	}
}


void Database_delete(struct Connection * conn, int id) {
	struct Address addr = { .id = id, .set = 0 };
	conn->db->rows[id] = addr;
}

void Database_list(struct Connection * conn) {
	int i = 0;
	struct Database * db = conn->db;

	for (i = 0; i < MAX_ROWS; i++) {
		struct Address * cur = &db->rows[i];

		if (cur->set) {
			Address_print(cur);
		}
	}
}



void Database_search(struct Connection * conn, char * text) {
	int i = 0;
	struct Database * db = conn->db;
	
	for (i = 0; i < MAX_ROWS; i++) {
		struct Address * cur = &db->rows[i];

		if (cur->set) {
			char * name = strcasestr(cur->name, text);
			char * email = strcasestr(cur->email, text);

			if (name && email) {
				Address_print(cur);
			} else if (name) {
				Address_print(cur);
			} else if (email) {
				Address_print(cur);
			} else {
				// Nothing to here	
			}
		}
	}
}

int main(int argc, char * argv[]) {
	if (argc < 3) {
		die("USAGE: ex17 <dbfile> <action> { action parameters }", NULL);
	}

	char * filename = argv[1];
	char action = argv[2][0];


	struct Connection * conn = Database_open(filename, action);
	int id = 0;

	switch (action) {
		case 'c':
			Database_create(conn);
			Database_write(conn);
			break;

		case 'g':
			if (argc != 4) {
				die("Need an ID to get.", conn);
			}

			if (argc > 3) { id = atoi(argv[3]); };

			if (id >= MAX_ROWS) {
				die("There's not that many records.", conn);
			}

			Database_get(conn, id);
			break;
		
		case 'f':
			if (argc != 4) {
				die("Need a String to search", conn);
			}
			char * text;
			if (argc > 3) {
				text = argv[3];
			}

			Database_search(conn,text);
			break;
		case 's':
			if (argc != 6) {
				die("Need id, name, email to set", conn);
			}
			Database_set(conn, id, argv[4], argv[5]);
			Database_write(conn);
			break;

		case 'd':
			if (argc != 4) {
				die("Need id to delete", conn);
			}
			Database_delete(conn, id);
			Database_write(conn);
			break;

		case 'l':
			Database_list(conn);
			break;
		default:
			die("Invalid action: c = create, g = get, set = set, d = del, l = list", conn);
	}

	Database_close(conn);

	return 0;

}
