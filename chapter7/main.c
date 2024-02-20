double Average(double array[], int n) {
    int i;
    double total;

    total = 0;
    for (i = 0; i < n; i++) {
        total += array[i];
    }
    return total / n;
}

void main() {

}