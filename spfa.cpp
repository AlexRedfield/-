/*
 * spfa.cpp
 *
 *  Created on: 2017��4��1��
 *      Author: Administrator
 */
#include<iostream>
#include<stdio.h>
#define maxnum 100
#define maxint 9999
using namespace std;

typedef struct Edge{
    int u, v;    // ��㣬�յ�
    int weight;  // �ߵ�Ȩֵ
}Edge;

Edge edge[maxnum];     // ����ߵ�ֵ
int  dis[maxnum]; 	   // ��㵽Դ����С����
int  vis[maxnum],q[maxnum],path[maxnum];
int nodenum, edgenum, source;    // �������������Դ��
int a[maxnum][maxnum];
int flag=0;//�������ȫ�ֱ���ֻ��Ϊ��·����������-
//int b[maxnum][maxnum];
// ��ʼ��ͼ
void init()
{
    // ����������������Դ��
    cin >> nodenum >> edgenum >> source;
    for(int i=1; i<=nodenum; ++i)
        dis[i] = maxint;
    dis[source] = 0;

    for(int i=1; i<=edgenum; ++i)
    {
        cin >> edge[i].u >> edge[i].v >> edge[i].weight;
        a[edge[i].u][edge[i].v]=edge[i].weight;

        if(edge[i].u == source)          //ע���������ó�ʼ���
            dis[edge[i].v] = edge[i].weight;

    }
}


void spfa(int s){
	for(int i=0; i<=nodenum; i++) dis[i]=maxint; //��ʼ��ÿ��i��s�ľ���
	dis[s]=0; vis[s]=1; q[1]=s;  //���г�ʼ��,sΪ���
	int i, v, head=0, tail=1;
	while (head<tail){   //���зǿ�
		head++;
		v=q[head];  //ȡ����Ԫ��
		vis[v]=0;   //�ͷŶ��׽�㣬��Ϊ��ڵ�����´������ɳ������ڵ㣬�������
		for(i=0; i<=nodenum; i++)  //�����ж���
		   if (a[v][i]>0 && dis[i]>dis[v]+a[v][i]){
				dis[i] = dis[v]+a[v][i];   //�޸����·
				path[i]=v;
				if (vis[i]==0){ // �����չ���i���ڶ����У����
					tail++;
					q[tail]=i;
					vis[i]=1;
				}
		   }
		}
	}
void printpath(int k){//�ݹ����·��

		if (path[k]!=0)
			{
			flag++;
			printpath(path[k]);
			}
		if(flag==0)
		{
		cout << k;
		}
		else
		{
		cout << k << '-';
		flag--;
		}
	}
int main()
{
	freopen("input.txt", "r", stdin);
	init();
	spfa(source);

	for(int i = 1 ;i <= nodenum; i++)
	{
		cout <<"the shortest path length from source to "<<i<<" is "<< dis[i]<<" ,the path is ";
		printpath(i);
		cout<<endl;
	}
	return 0;
}

