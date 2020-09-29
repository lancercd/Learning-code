#include "iostream"
#include "algorithm"

using namespace std;

int main() {

    return 0;
}

int n = Convert.ToInt32(input.Text);
if(n < 1)
{
    MessageBox.Show("输入的 N 不能小于 1");
    return;
}

ulong sum = 0, current = 1;
for(int i=1; i <= n; ++i)
{
    current *= Convert.ToUInt64(i);
    sum += current;
}

input.Text = "";
show.Items.Add(sum);
