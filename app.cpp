#include <iostream>
#include <string.h>
using namespace std;

int stricker,non_stricker,bowler,team1_played[11]={0},team1_fours[11]={0},team1_sixer[11]={0},team1_balls[11]={0},total_score,
team1_runs[11]={0},team1_overs[11]={0},team1_wicket[11]={0},team1_runs_given[11]={0};

int team2_played[11]={0},team2_fours[11]={0},team2_sixer[11]={0},team2_balls[11]={0},
team2_runs[11]={0},team2_overs[11]={0},team2_wicket[11]={0},team2_runs_given[11]={0};

void swap(int *a,int *b)
{
	int temp=*a;
	*a = *b;
	*b=temp;
}

int over_run_calculator(int striker, int non_stricker,int bowler)
{
			int ball = 1;
			string status;
			while(ball<=6)
			{
				int flag=0;
				cout<<"Enter Status of ball ";
				cin>>status;
				if(strcmp(status.c_str(),"0")==0)
				{
					ball++;
				}
				if(strcmp(status.c_str(),"1")==0 ) 
				{
						ball++;
						team1_balls[stricker]++;
						team1_runs[striker]+=1;
						total_score +=1;
						team2_runs_given[bowler]+=1;
						swap(&stricker,&non_stricker);
				}
				if(strcmp(status.c_str(),"3")==0)
				{
						ball++;
						team1_balls[stricker]++;
						team1_runs[striker]+=3;
						total_score +=3;
						team2_runs_given[bowler]+=3;
						swap(&stricker,&non_stricker);
				}
				if(strcmp(status.c_str(),"2")==0)
				{
						ball++;
						team2_runs_given[bowler]+=2;
						team1_balls[stricker]++;
						team1_runs[striker]+=2;
						total_score += 2;

				}
				if(strcmp(status.c_str(),"4")==0)
				{
						ball++;
						team1_balls[stricker]++;
						team1_runs[stricker]+=4;
						total_score +=4;
						team1_fours[stricker]++;	
				}
				
				if(strcmp(status.c_str(),"6")==0)
				{
						ball++;
						team1_balls[bowler]++;
						team1_sixer[stricker]++;
						total_score +=6;
						team1_runs[stricker]+=6;
					
				}
				if(strcmp(status.c_str(),"W")==0 || strcmp(status.c_str(),"w")==0)
				{
					ball++;
							team1_balls[stricker]++;
						if(flag==0)
						{
							team2_wicket[bowler]++;
							int out,new_player,player_position;
							cout<<"Enter Who is out "<<stricker <<" or "<<non_stricker;
							cin>>out;
							team1_played[out]=-1;
							cout<<"Enter new player ";
							cin>>new_player;
							while(team1_played[new_player]==-1 || team1_played[new_player]==1)
							{
								cout<<"Invalid Entry\n";
								cout<<"Enter player ";
								cin>>new_player;
							}
							team1_played[new_player]=1;
							cout<<"Is new player stricker or non-striker."<<endl;
							cout<<"Enter 1 for stricker and 0 for non-stricker ";
							cin>>player_position;
							int temp;
							if(out!=stricker)
							{
								temp=stricker;
							}
							else
							{
								temp = non_stricker;
							}
							if(player_position==1)
							{						
								stricker = new_player;
								non_stricker = temp;
							}
							else
							{
								stricker = temp;
								non_stricker = new_player;	
							}
						}
						else
						{
							flag=0;
							cout<<"It's free hit not out\n";
						}
					
				}
					
				if(strcmp(status.c_str(),"wd")==0)
						total_score++;
				if(strcmp(status.c_str(),"lb")==0||strcmp(status.c_str(),"byes")==0)
				{
					ball++;
						team1_balls[stricker]++;
						int temp=0;
						cout<<"\nEnter runs";
						cin>>temp;
						total_score+=temp;
				}	
				if(strcmp(status.c_str(),"nb")==0)
				{
						team1_balls[stricker]++;
						int temp=0;
						cout<<"\nEnter runs";
						cin>>temp;
						total_score+=temp;
						flag=1;
				}		
				
			}
			swap(&stricker,&non_stricker);
			team2_overs[bowler]++;
			return bowler;
}

int main()
{
	int overs,current;
	cout<<"Enter stricker no ";
	cin>>stricker;
	cout<<"Enter non-stricker no ";
	cin>>non_stricker;
	team1_played[non_stricker]=team1_played[stricker]=1;
	cout<<"Enter no.of overs ";
	cin>>overs;
	cout<<"Enter bowler ";
	cin>>bowler;
	for(int i=0;i<overs;i++)
	{
		current = over_run_calculator(stricker,non_stricker,bowler);
		cout<<"Enter bowler ";
		cin>>bowler;
		while(current==bowler)
		{
			cout<<"Invalid. Enter bowler ";
			cin>>bowler;
		}
	}
	cout<<"Total score "<<total_score<<endl;
	for(int i=0;i<11;i++)
	{
		cout<<i<<" "<< team1_runs[i]<<endl;
	}
}
