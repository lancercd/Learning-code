public partial class Form1 : Form
{
    //是否已经开始
    protected bool is_start = false;
    //随机数产生器
    protected Random ran = new Random();
    //运算范围  最大值
    protected const int MAX_NUM = 10;
    //运算范围  最小值
    protected const int MIN_NUM = 0;
    //运算符
    protected char[] OPERATION = { '+', '-', 'x', '÷'};
    //表达式  0=>num1  1=>num2 2=>operator 3=>ans
    protected int[] exp = new int[4];


    //util 转型成string
    private string getString<T>(T target)
    {
        return Convert.ToString(target);
    }
    //util 转型成int
    private int getInt<T>(T target)
    {
        return Convert.ToInt32(target);
    }

    //返回标准答案
    private int getAns()
    {
        return this.exp[3];
    }

    //返回表达式
    private string getExpression()
    {
        return getString(this.exp[0]) +
                OPERATION[this.exp[2]] +
                getString(this.exp[1]) +
                "=" +
                getString(this.exp[3]);
    }

    //检查当前是否已经结束了
    private bool check_end_status()
    {
        if (!this.is_start)
        {
            MessageBox.Show("已是结束状态,若要开始请先点击【开始按钮】");
            return false;
        }
        this.is_start = false;
        return true;
    }
    //检查当前是否已经开始了
    private bool check_start_status()
    {
        if (this.is_start)
        {
            MessageBox.Show("已是开始状态,若要结束请先点击【结束按钮】");
            return false;
        }
        this.is_start = true;
        return true;
    }

    //产生随机数
    private int create_num()
    {
        //最小范围  最大范围
        return this.ran.Next(MIN_NUM, MAX_NUM);
    }
    //产生操作符  (随机数)
    private int create_operator()
    {
        return this.ran.Next(0, OPERATION.Length);
    }

    //计算当前表达式的答案
    private double calculate_correct_answer(int number1, int number2, int op)
    {
        double ans = 0.0;
        double num1 = (double)number1;
        double num2 = (double)number2;
        switch (op)
        {
            case 0:
                ans = num1 + num2;
                break;
            case 1:
                ans = num1 - num2;
                break;
            case 2:
                ans = num1 * num2;
                break;
            case 3:
                ans = num1 / num2;
                break;
        }
        return ans;
    }

    //检查当前表达式是否合理
    private bool check_ele(int num1, int num2, int op)
    {
        //  除
        if (op == 3)
        {
            //除数为0
            if (num1 == 0 || num2 == 0) return false;
            //分数
            if (num1 < num2) return false;
            //不是整除（分数）
            if (num1 % num2 != 0) return false;
        }

        // 乘
        if (op == 2)
        {
            // MAX_NUM = 10  MAX_NUM * 2 = 20  两数相乘最大20
            if (num1 * num2 >= MAX_NUM * 2) return false;
        }

        // 加
        if (op == 2)
        {
            //两数相加最大20
            if (num1 + num2 >= MAX_NUM * 2) return false;
        }

        //减
        if (op == 1)
        {
            //小于0
            if (num1 - num2 < 0) return false;
        }
        return true;
    }

    //创建整个表达式所需要的数
    private int[] create_element()
    {
        //操作符
        int op = create_operator();
        //数字  两个随机数
        int num1, num2;
        //答案
        int ans;
        do
        {
            num1 = create_num();
            num2 = create_num();
        } while (!check_ele(num1, num2, op));  //判断是否合法
        //计算答案
        ans = (int)calculate_correct_answer(num1, num2, op);

        int[] ele = { num1, num2, op, ans };
        return ele;
    }

    //渲染 表达式
    private void render_exp(int num1, int num2, int op)
    {
        Num1.Text = getString(num1);
        Num2.Text = getString(num2);
        Opera.Text = getString(OPERATION[op]);
    }
    //在未开始时的提示渲染
    private void render_exp()
    {
        Num1.Text = "点击";
        Num2.Text = "开始";
        Opera.Text = "按钮";
    }

    //核心   启动
    private void run()
    {
        //清空 答案框
        User_ans.Text = "";
        //获取所有需要的元素  两个随机数  一个operator  一个ans
        int[] ele = create_element();
        //保存到全局数组中
        this.exp = ele;
        //渲染到  label中
        render_exp(ele[0], ele[1], ele[2]);
    }

    //点击了开始按钮
    private void start_btn_Click(object sender, EventArgs e)
    {
        if (!check_start_status()) return;
        //启动   (核心)
        run();
    }

    //结束按钮点击
    private void end_btn_Click(object sender, EventArgs e)
    {
        render_exp();
        if (!check_end_status()) return;


    }


    //答案输入完成后  进行点击的按钮
    private void submit_Click(object sender, EventArgs e)
    {
        if (!this.is_start)
        {
            MessageBox.Show("请先点击【开始按钮】哦");
            return;
        }
        //突然想到  少了判断
        if (User_ans.Text == "")
        {
            MessageBox.Show("宁还没有输入呢");
            return;
        }

        //处理答案  以及表达式
        deal_ans();


        //处理完成后  继续下一次运行
        run();
    }

    //处理答案  表达式
    private void deal_ans()
    {
        //用户输入的答案
        int user_ans = getInt(User_ans.Text);
        //标准答案
        int ans = getAns();
        //是否 正确  (用户答案啊  和  标准答案);
        bool is_correct = judge_ans(user_ans, ans);

        //渲染后面的结果到listbox中
        render_judged_exp(is_correct);
    }
    //结果渲染
    private void render_judged_exp(bool is_correct)
    {

        Show.Items.Add(getExpression() + "\t" + ((is_correct) ? "正确" : "错误"));
    }
    //判断答案是否相等
    private bool judge_ans(int current, int target)
    {
        return current == target;
    }

}
