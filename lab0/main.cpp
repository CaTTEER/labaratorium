#include <iostream>

using std::cout, std::endl, std::cin;

constexpr float USD_EXCHANGE_RATE = 0.26;

float static convert_zloty_to_usd(float amount)
{
    return amount * USD_EXCHANGE_RATE;
}

float static zloty_input()
{
    float input_zloty_amount;
    cout << "Write zloty amount:", cin >> input_zloty_amount;
    return input_zloty_amount;
}

void static process_zloty_to_usd()
{
    float zloty_amount = zloty_input();
    float usd_amount = convert_zloty_to_usd(zloty_amount);
    cout << "Transform result: " << usd_amount << "$" << endl;
}

int main()
{
    process_zloty_to_usd();
}

