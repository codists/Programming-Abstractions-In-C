double Average(double array[], int n) {
    int i;
    double total;

    total = 0;
    for (i = 0; i < n; i++) {
        total += array[i];
    }
    return total / n;
}
int LinearSearch(int key, int array[], int n) {
    int i;

    for (i = 0; i < n; i++) {
        if (key == array[i]) {
            return i;
        }
    }
    return -1;
}

void main() {

}