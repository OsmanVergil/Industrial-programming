class rational {
    private:
    int a, b;
    public:
    rational ();
    rational (int a1, int b1);
    void set (int a1, int b1);
    void show ();
    int get_a ();
    int get_b ();
    friend rational operator - (rational &d1, rational &d2);
    rational operator= (rational frac);
};

int NOD (int a, int b);