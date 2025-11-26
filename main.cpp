    #include<iostream>
    #include<cctype>
    #include<algorithm>
    #include<chrono>
    #include<thread>
    #include<cmath>
    #include <iomanip>
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
    void anim_txt (const std::string  &text,int delay_ms = 80 )
        {
            for (char a : text)
            {
                std::cout<<a<<std::flush;
                std::this_thread::sleep_for(std::chrono::milliseconds(delay_ms));
            }
        }
void convert_time(long double total_seconds)
        {
            long double seconds = total_seconds;
            long double years = seconds/31557600;
            if (years>1)
            {
                cout<<noshowpoint;
                cout<<"Years: "<<static_cast<int>(years)<<endl;
               seconds = fmod(years,31557600);
            }
            long double days = seconds/86400;
            if (days>1)
            {
                cout<<"Days: "<<static_cast<int>(days)<<endl;
                seconds = fmod(days,86400);
            }
            long double hours = seconds/3600;
            if (hours>1)
            {
                cout<<"Hours: "<<static_cast<int>(hours)<<endl;
                seconds = fmod(hours,3600);
            }
            long double minutes = seconds/60;
            if (minutes>1)
            {
                cout<<"Minutes: "<<static_cast<int>(minutes)<<endl;
                seconds = fmod(minutes,60);
            }
            cout<<"Seconds: "<<static_cast<int>(seconds)<<endl;
        }
    int main()
    {
        int score{0};
        int number{0};
        int char_size{0};
        long double total_combo{0};
        long double tt_crack{0};
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
            char_size+=26;
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
            char_size+=26;
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
            char_size+=10;
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
            char_size+=20;
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
            total_combo=pow(char_size,number);
            tt_crack=total_combo/6000000;//6000000 is the guesses per second according to my laptop
            convert_time(tt_crack);
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