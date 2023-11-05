int gcdExtended(int a, int b, int &x, int &y) {
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }

    int x1, y1;
    int gcd = gcdExtended(b % a, a, x1, y1);

    x = y1 - (b / a) * x1;
    y = x1;

    return gcd;
}

//Function to calculate the modular inverse of 'a' modulo 'm'
int modInverse(int a, int m) {
    int x, y;
    int gcd = gcdExtended(a, m, x, y);

    if (gcd != 1) {
        // Modular inverse doesn't exist
        return -1;
    }

    // Ensure x is positive
    return (x % m + m) % m;
}