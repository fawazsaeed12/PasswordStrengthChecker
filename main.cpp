#include<iostream>
#include<cctype>
#include<algorithm>
#include<cmath>
using namespace std;


    //function to check repetitions
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
    //function to check repetitions


    // to display brute force time
    void convert_time(long double total_seconds)
    {
        long double seconds = total_seconds;
        long double years = seconds/31557600;
        if (years>1)
            {
               cout<<"Years: "<<static_cast<long long int>(years)<<endl;
               seconds = fmod(seconds,31557600);
            }
        long double days = seconds/86400;
        if (days>1)
            {
                cout<<"Days: "<<static_cast<long long int>(days)<<endl;
                seconds = fmod(seconds,86400);
            }
        long double hours = seconds/3600;
        if (hours>1)
            {
                cout<<"Hours: "<<static_cast<long long int>(hours)<<endl;
                seconds = fmod(seconds,3600);
            }
        long double minutes = seconds/60;
        if (minutes>1)
            {
                cout<<"Minutes: "<<static_cast<long long int>(minutes)<<endl;
                seconds = fmod(seconds,60);
            }
                cout<<"Seconds: "<<static_cast<long long int>(seconds)<<endl;
        }
    // to display brute force time


    int main()
    {
        //variables
        int score{0};
        int number{0};
        int brute_option{0};
        int char_size{0};
        long double total_combo{0};
        long double tt_crack{0};
        string pass;
        bool capital{false};
        bool small{false};
        bool digit{false};
        bool symbol{false};
        long long int brute_power{0};
        //variables


            cout<<"Please enter your password to check it's strength: ";
            cin>>pass;


            //evaluating the part where we check for
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
            //evaluating the part where we check for


           // password determine part
        if (score>=0&&score<=30)
        {
            cout<<"Your password is weak";
        }else if (score>=31&&score<=60)
        {
            cout<<"Your password is Medium";
        }else if (score>=61&&score<=100)
        {
            cout<<"Your password is strong ";
        }   //password determine part

    cout<<"\nselect if you want to brute force with the power of\n1 for Average pc\n2 for Modern Gpu\n3 for Hacking Rig\n";
        cin>>brute_option;
            //brute force guess per second part
        total_combo=pow(char_size,number);
        switch (brute_option)
        {
        case 1:
            brute_power=100000000;//100million per sec
            break;
        case 2:
            brute_power=1000000000;//1 billion per sec
            break;
        case 3:
            brute_power=10000000000;//10 billion per sec
            break;
        default:
            brute_power=0;
            cout<<"Invalid option";
            break;
        }

        tt_crack=total_combo/brute_power;
        if(tt_crack>9.22e18)
        {
            cout<<"This password is unbreakable\n";
        }
        else
        {
            convert_time(tt_crack);
        }   //brute force guess per second part


            //suggestions for better pass
        if (capital==false||small==false||digit==false||symbol==false)
        {
            cout<<"SUGGESTIONS:\n";
            if (capital==false)
            {
                cout<<"Use upper case character"<<endl;
            }
            if (small==false)
            {
                cout<<"Use lowercase character"<<endl;
            }
            if (digit==false)
            {
                cout<<"Use numbers"<<endl;
            }
            if (symbol==false)
            {
                cout<<"Use special symbols"<<endl;
            }
        }
        //suggestions for better pass
    }