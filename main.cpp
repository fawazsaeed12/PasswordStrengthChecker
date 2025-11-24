#include<iostream>
#include<cctype>
#include<algorithm>
#include<chrono>
#include<thread>
using namespace std;
    bool repe(string s)
    {
        std::sort(s.begin(), s.end());
            for (size_t i = 0; i+1 < s.size(); ++i)
            {
                if (s[i] == s[i+1])
                {
                    return true;
                 }
            }
                return false;
    }
void anim_txt (const std::string  &text,int delay_ms = 100 )
    {
        for (char a : text)
        {
            std::cout<<a<<std::flush;
            std::this_thread::sleep_for(std::chrono::milliseconds(delay_ms));
        }
    }
int main()
{
    int score{0};
    int number{0};
    int possible_char{0};
    string pass;
    bool capital{false};
    bool small{false};
    bool digit{false};
    bool symbol{false};
        anim_txt("Please enter your password to check it's strength: ");
    cin>>pass;
    for (char c : pass)
    {
        number++;
    }
    if (number>12)
    {
        score +=20;
    }
    for (char c : pass)
    {
        if (isupper(c))
        {
            capital = true;
            break;
        }
    }
    if (capital==true)
    {
        score+=10;
    }
    for (char c : pass)
    {
        if (islower(c))
        {
            small = true;
            break;
        }
    }
    if (small==true)
    {
        score+=15;
    }
    for (char c : pass)
    {
        if (isdigit(c))
        {
            digit=true;
            break;
        }
    }
    if (digit==true)
    {
        score+=15;
    }
    for (char c : pass)
    {
        if (!isalpha(c)&&!isdigit(c))
        {
            symbol=true;
            break;
        }
    }
    if (symbol==true)
    {
        score+=15;
    }
    if (capital ==true && small==true && digit==true && symbol==true)
    {
        score+=25;
    }
    if (number<6)
    {
        score-=10;
    }
        if (repe(pass))
        {
            score-=10;
        }
        if (score<0)
        {
            score=0;
        }
    if (score>=0&&score<=30)
    {
        anim_txt("Your password is weak");
    }else if (score>=31&&score<=60)
    {
        anim_txt("Your password is Medium");
    }else if (score>=61&&score<=100)
    {
        anim_txt("Your password is strong ");
    }



}