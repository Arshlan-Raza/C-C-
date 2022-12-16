#include <iostream>

using namespace std;

int main()

{
    int small_rooms,large_rooms,total_small_room_cost,total_large_room_cost;
    
    cout<<"Enter the number of large rooms:"<<endl;
    cin>>large_rooms;
    cout<<"Enter the number of small rooms:"<<endl;
    cin>>small_rooms;
    cout<<"Price per small rooms:$25"<<endl;
    cout<<"Price per large rooms:$35"<<endl;
    total_small_room_cost=small_rooms*25;
    total_large_room_cost=large_rooms*35;
    cout<<"\nCost:$" <<total_small_room_cost+total_large_room_cost<<endl;
    cout<<"Tax $6.6"<<endl;
    cout<<"\n======================================================="<<endl;
    cout<<"\nTotal estimate is "<<total_small_room_cost+total_large_room_cost+6.6<<endl;
    cout<<"This estimate is valid for 30 days";
    return 0;

}