# include<iostream>

void add(long b1, long b2){
    int carry = 0;
    int sum[32];
    int i = 0;
    while (b1 != 0 || b2 != 0)
        {
            sum[i++] = (int)((b1 % 10 + b2 % 10 + carry) % 2);
            carry = (int)((b1 % 10 + b2 % 10 + carry) / 2);
            b1 = b1 / 10;
            b2 = b2 / 10;
        }
        if (carry != 0) {
            sum[i++] = carry;
        }
        --i;
        std::cout <<"Output: ";
        while (i >= 0) {
            std::cout << sum[i--];
        }
    std::cout << std::endl;
    }


int main(void){
    long b1 = 111011101011;
    long b2 = 11;
    add(b1,b2);
}
