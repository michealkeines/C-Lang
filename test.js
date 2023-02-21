function test() {
    let arr = [20, 10, -80, 10, 10, 15, 35];
    let count = 0;
    let index = 0;
    for (let i = 1; i < arr.length; i++) {
        let sum1 = 0;
        let sum2 = 0;
        for (let j = 0; j < arr.length; j++) {
            if (j < i) {
                sum1 = sum1 + arr[j]
            }
            else if (j > i) {
                sum2 = sum2 + arr[j]
            }
        }
        console.log(sum1, sum2);
        if (sum1 == sum2) {
            index = i;
            count++;
            break;
        }
    }
    if (count == 0) {
        return -1;
    } else {
        return index;
    }
}

console.log(test());


