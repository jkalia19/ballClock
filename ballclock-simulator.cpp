//  main.cpp
//  ballclock
//
//  Created by Jeewan Kalia on 2017-12-29.
//  Copyright © 2017 Jeewan Kalia. All rights reserved.

#include <iostream>
#include <queue>
#include <stack>
/*int i = 0;  !!!! Without DEQUE
int count_days=0;
int count_balls=1;
int STATUS = 0;
int COMPLETED = 1;
int OVERFLOW = 2;
int ERROR = 3;
int COMPARE = 4;
int s_minutes_capacity = 4;
int s_5minutes_capacity = 11;
int s_hours_capacity = 10;
std::queue<int> q_all;
std::stack<int> s_minutes;
std::stack<int> s_5minutes;
std::stack<int> s_hours;
void initialize_val();
int insert_qminutes();
int insert_q5minutes();
int insert_qhours();*/
/*
void show()
{
    std::queue<int> temp = q_all;
    for(i=30; i>=1; i--)
    {
        std::cout<<temp.front()<<" ";
        temp.pop();
    }
}
void initialize_val()
{
    for(i=30; i>=1; i--)
    {
        q_all.push(i);
    }
}
int insert_qminutes()
{
    std::cout<<" FIRST BAA BAA "<<count_balls<<std::endl;// BALLS COUNT
    if(count_balls <= s_minutes_capacity)
    {
        s_minutes.push(q_all.front());//push data
        q_all.pop(); count_balls++;
    }
    else if(count_balls > s_minutes_capacity)// IF FULL
    {
        show();
        return OVERFLOW;
    }
    else
    {
        std::cout<<"ERROR 1 BAA BAA"<<std::endl;
        return ERROR;
    }
    return 0;
}
int insert_q5minutes()
{
    std::cout<<"SECOND BAA BAA "<<count_balls<<std::endl;// BALLS COUNTER
    if (count_balls > s_minutes_capacity && count_balls <= (s_minutes_capacity + s_5minutes_capacity) )
    {
        s_5minutes.push(q_all.front());// push data
        q_all.pop();
        for(i = 0; i < 4; i++)// empty s_minutes
        {
            q_all.push(s_minutes.top());
            s_minutes.pop();
        }
        count_balls++;
        std::cout<<count_balls;
    }
    else if (count_balls == (s_minutes_capacity + s_5minutes_capacity))// IF FULL
        return OVERFLOW;
    else
    {
        std::cout<<"ERROR 2 BAA BAA"<<std::endl;
        return ERROR;
    }
    return 0;
}
int insert_qhours()
{
    std::cout<<"THIRD BAA BAA "<<count_balls<<std::endl;
    if(count_balls > (s_minutes_capacity + s_5minutes_capacity) &&
       count_balls < (s_minutes_capacity + s_5minutes_capacity + s_hours_capacity))
    {
        std::cout<<"front"<<q_all.front()<<std::endl;
        s_hours.push(q_all.front());//push data
        q_all.pop();
        for(i = 0; i<=(s_5minutes_capacity); i++)//empty 5_minutes
        {
            q_all.push(s_5minutes.top());
            s_5minutes.pop();
        }
        count_balls++;
    }
    else if(count_balls == (s_minutes_capacity + s_5minutes_capacity + s_hours_capacity))// IF FULL
    {
        count_days++; count_balls = 0;
        for(i = 0; i <= (s_minutes_capacity + s_5minutes_capacity + s_hours_capacity); i++ )
        {
            q_all.push(s_hours.top());
            s_hours.pop();
        }
        q_all.push(q_all.front());
        q_all.pop();
        return OVERFLOW;
    }
    else
    {
        std::cout<<"ERROR 3 BAA BAA"<<std::endl;
        return ERROR;
    }
    return 0;
}
int compare_q()
{
    std::queue<int> temp = q_all;
    for(i = 30; i>=1; i--)
    {
        if(i!=temp.front())
            return ERROR;
        else
            temp.pop();
    }
    return COMPLETED;
}
int main()
{
    initialize_val();
    show();
    while(STATUS != COMPLETED)
    {
        insert_qminutes();
        if( insert_qminutes() == OVERFLOW)
        {
            if(insert_q5minutes() != OVERFLOW)
                insert_q5minutes();
            else if(insert_q5minutes() == OVERFLOW)
                STATUS = insert_qhours();
            else if (insert_q5minutes() == ERROR)
                std::cout<<"ERROR OCCURED in 5 minutes"<<std::endl;
        }
        else if (insert_qminutes() == ERROR)
        {
            std::cout<<"ERROR OCCURED in minutes"<<std::endl;
        }
    }
    show();
}
*/
#include<deque>

using namespace std;//with DEQUE

class ballclock{
    
    deque<int> minq,fiveminq,hourq,bottomq1;
    int counter,size;
    
public:
    
    ballclock(int s){
        size=s;
        counter=0;
        for(int i=1;i<=size;i++){
            bottomq1.push_back(i);
        }
    }
    
    int countdays(){
        return (counter/2);
    }
    
    void calculatedays(){
        
        do{
            
            if(minq.size()<4){
                minq.push_back(bottomq1.front());
                bottomq1.pop_front();
            }else{
                
                for(int i=1;i<=4;i++){
                    bottomq1.push_back(minq.back());
                    minq.pop_back();
                }
                
                if(fiveminq.size()<11){
                    fiveminq.push_back(bottomq1.front());
                    bottomq1.pop_front();
                }else{
                    
                    for(int i=1;i<=11;i++){
                        bottomq1.push_back(fiveminq.back());
                        fiveminq.pop_back();
                    }
                    if(hourq.size()<=12){
                        hourq.push_back(bottomq1.front());
                        bottomq1.pop_front();
                    }else{
                        counter++;
                        
                        for(int i=1;i<=12;i++){
                            bottomq1.push_back(hourq.back());
                            hourq.pop_back();
                        }
                    }
                }
                
            }
            
            
            
            
        }while(!compare());
        
    }
    
    int compare(){
        
        //    if(bottomq1.size()==size){
        deque<int>::iterator p=bottomq1.begin();
        
        for(int i=1;i<=size;i++){
            
            if(*p++!=i){
                return false;
            }
            
        }
        
        return true;
        
        //  }else{
        //    return false;
        //}
    }
};


int main(){
    
    int s[]={30,45,0};
    
    for(int i=0;i<3;i++){
        if(s[i]<27&&s[i]>127){
            cout<<"Invalid input"<<endl;
        }
        ballclock clock(s[i]);
        clock.calculatedays();
        cout<<s[i]<<" balls cycle after "<<clock.countdays()<<" days"<<endl;
    }
    
    return 0;
}
