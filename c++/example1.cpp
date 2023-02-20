#include <iostream>

namespace test_name1 {
    float test()
    {
        std::cout << "test from namespace 1\n";
        return 3.15;
        //test
    }
}

namespace test_name2 {
    float test()
    {
        std::cout << "test from namespace 2\n";
        return 1.0;
        //test
    }
}

int is_even_comp(int value)
{
    if (value % 2 == 0)  {
        return 1;
    } else {
        return 0;
    }
}

void switch_condition(char test)
{
    switch(test) {
        case 'A':
            std::cout << "Initial starts with A" << "\n";
            break;
        case 'B':
            std::cout << "Initial starts with A" << "\n";
            break;
        case 'C':
            std::cout << "Initial starts with A" << "\n";
            break;
        case 'D':
            std::cout << "Initial starts with A" << "\n";
            break;
        default:
            std::cout << "Didnt match anything" << "\n";
            break;
    }
    
}


void print_numbers()
{

    int count = 10;
    for(int i = 0; i < count; i++) {
        std::cout << "current: " << i << "\n";
    }
}

/*
    def print_numbers(count):
        for i in range(count):
            print(i)
*/

// def is_greater(value)

class Box {
    private:
        int length;
        int breadth;
        int height;
    
    public:
        int tst;

        Box() {
            std::cout << "Defualt constructor called" << "\n";
            this->length = 0;
            this->height = 0;
            this->breadth = 0;
            this->tst = 0;
        }

        Box(int length, int breadth, int height) {
            std::cout << "Constructor with three parameters" << "\n";
            this->breadth = breadth;
            this->height = height;
            this->length = length;
        }
        Box(int length, int breadth) {
            std::cout << "Constructor with two parameters" << "\n";
            this->breadth = breadth;
            this->height = 0;
            this->length = length;
        }

        Box(Box *pointer) {
            this->length = pointer->length;
            this->height = height;
        }

};


class Coordinates {
    public:
     int x;
     int y;

    Coordinates () {
        this->x = 0;
        this->y = 0;
    }

    Coordinates (int x_input, int y_input): x(x_input), y(y_input) {}

    Coordinates operator+ (Coordinates &pointer) {
        Coordinates third;
        third.x = this->x + pointer.x;
        third.y = this->y + pointer.y;
        return third;
    }
};

class Girls {
    public:
        int dob;
    
        Girls() {
            this->dob = 0;
        }

        Girls(int date) {
            this->dob = date;
        }

        Girls(Girls *pointer) {
           // eve->dob = daisy->dob;
            this->dob = pointer->dob;
        }
};

class Animal {
    public:
        char *name;

    protected:
        int total;

    private:
        int total_private;
};

class Cat: Animal {
    public:
        int cat_count;
        
        void print_total();

        void print_total2() {
            std::cout << "just printing" << "\n";
        }

        int test_ret() {
            return 2 * 3;
        }

        // void print_total() {
        //     std::cout << "current total: " << total_private << "\n";
        //     std::cout << "current total: " << total << "\n";
        // }
};

void Cat::print_total() {
    std::cout << "just printing" << "\n";
}

class Dog {
        public:
        int dog_count;
        
        // void print_total() {
        //     std::cout << "current total: " << total << "\n";
        // }
};

class Vectors {
    public:
        int latitude;

    Vectors() {
        this->latitude = 0;
    }

    Vectors(int lat)
    {
        this->latitude = lat;
    }

    Vectors operator+ (Vectors &india)
    {
        Vectors alaska;
        alaska.latitude = this->latitude + india.latitude;
        return alaska;
    }
};

class Total {
    private:
        static int total;

    public:
        Total() {
            this->total += 1;
        }
        
        int get_total() {
            return this->total;
        }

        static void get_class_name() {
            int current = Total::total;
            std::cout << "Total Class\n" << current << "\n";
        }

};

int Total::total = 0;

class Climate {
    private:
        float celsius;
        float fahrenheit;
    public:
        Climate() {
            this->celsius = 0.0;
            this->fahrenheit = 0.0;
        }
        Climate(float a, float b) {
            this->celsius = a;
            this->fahrenheit = b;
        }
    
        void duplicate(const Climate &other) {
            std::cout << other.celsius << "\n";
            std::cout << other.fahrenheit << "\n";
        }
};

void print_value(int count) {
    std::cout << count << "\n";
}

int is_even(int value) {
    if (value % 2 == 0) {
        return 1;
    } else {
        return 0;
    }
}

void get_value(int value) {
    value += 1;
    std::cout << "inside get_value " << value << "\n";
}

void get_reference(int &value) {
    value += 1;
    std::cout << "inside get reference " << value << "\n";
}


int main()
{

    int a = 10;

    get_value(a);

    std::cout << "after get value "  << a << "\n";

    get_reference(a);

    std::cout << "after get reference " <<  a << "\n";

    // int count = 4;
    // int value = 2;

    // print_value(count);

    // int result;

    // result = is_even(value);

    // std::cout << "result: " << result << "\n";


    // int a = 19;
    // int *ptr = &a;

    // // dereferencing
    // int b = *ptr; // now b = 19

    // int* b { &a };

    // int *b = &a;

    // void add_two(int *a) {
    //     int temp = *a + 2;
    //     *a = temp;
    // }


    // Climate climate_obj1;
    // Climate climate_obj2(1.2, 1.5);

    // climate_obj2.duplicate(climate_obj2);

    return 0;

    // Total test1;

    // test1.get_class_name();

    // std::cout << "total1: " << test1.get_total() << "\n";

    // Total test2;
    // std::cout << "total2: " << test2.get_total() << "\n";

}


    // Coordinates x1(1,2);
    // Coordinates y1(3,7);

    // int a = 1;
    // int b = 2;
    // int c = a + b;

    // Coordinates z1 = x1 + y1;
    // Coordinates z2 = x1 - y1;

    // std::cout << "x1: " << x1.x << "," << x1.y << "\n";
    // std::cout << "y1: " << y1.x << "," << y1.y << "\n";
    // std::cout << "z1: " << z1.x << "," << z1.y << "\n";


    // Box test_box;
    // Box test_box1(1,2,3);
    // Box test_box2(1,2);
    // Box *ptr_to_box = &test_box1;
    // Box final_box(ptr_to_box);


    // Girls maya(15);

    // // maya is an object of an class Girls

    // Girls daisy(20);

    // // dailsy is an object of an class Girls

    // Girls eve(&daisy);

    // eve is an objects of an class Girls


   // Box* test_box = new Box();
    // test_box is an object of a class Box


    // int test = 10;

    // Animal forest_animals;
    // // forest_animals is an object of a Animal class

    // Cat cat1;
    // // cat1 is an object of a Cat class

    // cat1.print_total2();
    // cat1.print_total();

    // forest_animals.name = "sdf";


    // //test_box.length = 10;
    // test_box.test_public = 10;

    // int is_even;

    // //is_even = is_even_comp(2);

    // // print_numbers();
    // // switch_condition('P');

    // int test[5] = {1,2,3,43,5};
    // int test2[] {2,23,2,4,2,32,3};
    // int test2[] = {2,23,2,4,2,32,3};

   // std::cout << "even: " << is_even << "\n";

//     return 0;
// }


