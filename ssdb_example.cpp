#include <stdio.h>
#include <map>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <string>
#include <vector>
#include <time.h> 
#include <sys/time.h>
#include <sys/types.h>  
#include <unistd.h>
#include <pthread.h>  
#include <iostream>
#include "SSDB_client.h"
using namespace std;
#define NUM_THREADS 5
int Random(int m, int n)
{
	int pos, dis;
	if (m == n)
	{
		return m;
	}
	else if (m > n)
	{
		pos = n;
		dis = m - n + 1;
		return rand() % dis + pos;
	}
	else
	{
		pos = m;
		dis = n - m + 1;
		return rand() % dis + pos;
	}
}
char* readline(char *buf, int num){
	char *ret = fgets(buf, num , stdin);
	if(!ret){
		return NULL;
	}
	if(strlen(ret) > 0){
		ret[strlen(ret) - 1] = '\0';
	}
	return ret;
}
//进程执行函数---------------------------------------------------------------
void *  
myprocess (void* args)  
{
	ssdb::Client *client = ssdb::Client::connect("127.0.0.1", 8888);
	
	ssdb::Status s;
	std::map<std::string, std::string> kvs;
	// kvs.insert(std::make_pair("k1", "v100"));
	// kvs.insert(std::make_pair("k2", "v102"));
	// s = client->multi_set(kvs);
	//assert(s.ok());
	int area_start=71;
	area_start=*((int *)args);
	printf ("threadid is, working on task %d\n",area_start); 
	int i, j,k,m, n;
	char value[100] = {0};
	char key[50] = {0};
	char command[200] = {0};
	string string_key;
	string string_value;
	struct  timeval  start;
	struct  timeval  end;
	struct  timeval  start2;
	struct  timeval  end2;
	unsigned long timer;
	//TStrStrMap::iterator p;
	int szTime = (int)time(NULL);
	//srand(szTime);
	m = 200;
	n = 240;
	//redisReply *replay=NULL;
	int timeout=10000;
	struct timeval tv;
	tv.tv_sec=timeout/1000;
	tv.tv_usec=timeout*1000;
	float ac;
	int ad;
	if(client == NULL){
		printf("fail to connect to server!\n");
		return 0;
	}
	//-----------------------------------------------
	szTime = (int)time(NULL);
	srand(szTime);
	int temp1;
	int temp2;
	temp2=szTime;
	int tm_sec;
	int tm_min; //代表目前分数，范围0-59
	int tm_hour;//从午夜算起的时数，范围为0-23
	int tm_mday; //目前月份的日数，范围01-31
	int tm_mon; //代表目前月份，从一月算起，范围从0-11
	int tm_year;//从1900 年算起至今的年数
	struct tm *p;
	time_t timep;
	time(&timep);
	p=gmtime(&timep);
	
	printf("%4d%02d%02d",(1900+p->tm_year),(1+p->tm_mon),p->tm_mday);
	tm_sec=p->tm_hour*60+tm_sec;
	tm_year=(1900+p->tm_year);
	tm_mon=(1+p->tm_mon);
	tm_mday=p->tm_mday;
	tm_hour=p->tm_hour;
	string time_fmt;
	string resource_id_fmt;
	string key_fmt;
	sprintf(time_fmt, "%04d%2d%2d%02d",tm_year,tm_mon,tm_mday,tm_hour);
	sprintf(key_fmt,"%s:%s:%s:%s",time_fmt.c_str(),resource_id_fmt.c_str(),tm_sec,value);
	//-----------------------------------------------
	//replies = malloc(sizeof((void *)redisReply) * num);
	// while(true)
	// {
		// timer=0;
		// gettimeofday(&start,NULL);
		// string_key = "";
		// string_value = "";
		// ad=1;
		// szTime = (int)time(NULL);
		// srand(szTime);
		// //string command;
		// ac=1;
		// //printf("count is%d",ac);
		// //ac = (Random(m, n) / 10.0);
		// //int ad=1;
		// //----------------------------------------------------------------------------------------------------------
		// timer=0;
		// gettimeofday(&start,NULL);
		// ad=1;
		// szTime = (int)time(NULL);
		// srand(szTime);
		// //string command;
		// ac=1;
		// //printf("count is%d",ac);
		// ac = (Random(m, n) / 10.0);
		// //int ad=1;
		// //replay = malloc(sizeof(struct redisReply)*num);
		
		
		// // for(i=area_start;i<area_start+25;i++)
		// // {
			// // for(j=0;j<=50;j++)
			// // {
				// // // sprintf(key, "%d_S0E%dA%d",i,j,k);
				// // // sprintf(value, "{\"real_value\":\"%0.1f\",\"status\":1,\"save_time\":\"%d\",\"display_value\":\"%0.1f\"}",ac,szTime,ac);
				// // string_key = key;
				// // string_value = value;
				// // //sprintf(command,"mset %s %s",string_key.c_str(),string_value.c_str());
				// // //kvs.insert(std::make_pair("k1", "v1"));
				// // kvs.insert(std::make_pair(string_key,string_value));
				
			// // }
			// // s = client->multi_set(kvs);	
			// // assert(s.ok());
			// // kvs.clear();
		// // }
		
		// printf("\n");
		// gettimeofday(&end,NULL);
		// timer = 1000000 * (end.tv_sec-start.tv_sec)+ end.tv_usec-start.tv_usec;
		// printf("timer = %ld us\n",timer);
		// sleep(3);
	//}
	//kvs.clear();
	//delete client;
	//cout << szTime << endl;
	
    //sleep (2);/*休息一秒，延长任务的执行时间*/  
    return NULL;  
}
//----------------------------------------------------------------
void *  
myprocess2()  
{
	ssdb::Client *client = ssdb::Client::connect("127.0.0.1", 8888);
	
	ssdb::Status s;
	std::map<std::string, std::string> kvs;
	// kvs.insert(std::make_pair("k1", "v100"));
	// kvs.insert(std::make_pair("k2", "v102"));
	// s = client->multi_set(kvs);
	//assert(s.ok());
	int area_start=71;
	printf ("threadid is, working on task %d\n",area_start); 
	int i, j,k,m, n;
	char value[100] = {0};
	char key[50] = {0};
	char command[200] = {0};
	string string_key;
	string string_value;
	struct  timeval  start;
	struct  timeval  end;
	struct  timeval  start2;
	struct  timeval  end2;
	unsigned long timer;
	//TStrStrMap::iterator p;
	int szTime = (int)time(NULL);
	//srand(szTime);
	m = 200;
	n = 240;
	int num=1000000;
	//redisReply *replay=NULL;
	int timeout=10000;
	struct timeval tv;
	tv.tv_sec=timeout/1000;
	tv.tv_usec=timeout*1000;
	float ac;
	int ad;
	if(client == NULL){
		printf("fail to connect to server!\n");
		return 0;
	}
	timer=0;
	gettimeofday(&start,NULL);
	string_key = "";
	string_value = "";
	ad=1;
	szTime = (int)time(NULL);
	srand(szTime);
	//string command;
	ac=1;
	//printf("count is%d",ac);
	//ac = (Random(m, n) / 10.0);
	//int ad=1;
	//----------------------------------------------------------------------------------------------------------
	timer=0;
	gettimeofday(&start,NULL);
	ad=1;
	szTime = (int)time(NULL);
	srand(szTime);
	//string command;
	ac=1;
	//printf("count is%d",ac);
	//ac = (Random(m, n) / 10.0);
	//int ad=1;
	num=1000000;
	sprintf(key, "%d_S0EA",i);
	sprintf(value, "{\"real_value\":\"%0.1f\",\"status\":1,\"save_time\":\"%d\",\"display_value\":\"%0.1f\"}",ac,szTime,ac);
	string_key = key;
	string_value = value;
	//sprintf(command,"mset %s %s",string_key.c_str(),string_value.c_str());
	s = client->set(key, "test_val");
		assert(s.ok());
	//replay = malloc(sizeof(struct redisReply)*num);
	// for(int i=0;i<10;i++)
	// {
		// sprintf(key, "%d_S0EA",i);
		// sprintf(value, "{\"real_value\":\"%0.1f\",\"status\":1,\"save_time\":\"%d\",\"display_value\":\"%0.1f\"}",ac,szTime,ac);
		// string_key = key;
		// string_value = value;
		// //sprintf(command,"mset %s %s",string_key.c_str(),string_value.c_str());
		// kvs.insert(std::make_pair("k1", "v1"));
		// s = client->multi_set(kvs);
		// assert(s.ok());
	// }
	
	
	printf("\n");
	gettimeofday(&end,NULL);
	timer = 1000000 * (end.tv_sec-start.tv_sec)+ end.tv_usec-start.tv_usec;
	printf("timer = %ld us\n",timer);
	//sleep(5);
	kvs.clear();
	delete client;
	//cout << szTime << endl;
	
    //sleep (2);/*休息一秒，延长任务的执行时间*/  
    return NULL;  
}
//---------------------------------------------------------------
int main(int argc, char **argv){
	
	// myprocess2();
	// connect to server
	const unsigned int thread_number=5;
	int starts;
	starts =0;
	int area_number[4]={0,25,50,75};
	pthread_t thread1_id[NUM_THREADS];  
	int indexes[NUM_THREADS];
	//start=area_number[0];
	//pthread_create(&thread1_id[0], NULL, myprocess,(void *)&(start)); 
    //pthread_t thread2_id; 
	for(int i=0;i<4;i++)
	{
		starts=area_number[i];
		pthread_create(&thread1_id[i], NULL, myprocess,(void *)&(area_number[i]));
		printf("Current pthread id =%s,start is %d\n",thread1_id[i],area_number[i]);
	}

    //pthread_create(&thread2_id, NULL, myprocess,NULL);  
	for(int i=0;i<4;i++)
	{
		pthread_join(thread1_id[i], NULL);
	}
	
	return 0;
}
