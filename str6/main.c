#include <stdio.h>
#include <malloc.h>
#include<string.h>

typedef struct bidder_tag
{
  char name1[50];
  char name2[50];
  int ID;
  int sum;
  struct bid_tag *m_bid;
  int bidcnt;
} bidder;

typedef struct bid_tag
{
  bidder* who;
  int price;
  int win;
} bid;

typedef struct auction_tag
{
  int auction_num;
  char name[50];
  int unit;
  bid* bid_arr;
  int bid_num;
} auction;

typedef struct house_tag
{
  auction** active;
  int auction_num;
  bidder* who;
  int bidder_num;
} house;

static int auction_cnt=114547;
static int bidder_cnt=111;

auction* init_auction()
{
	auction* act;
	int unit;
	char str[50];
	act=(auction*)malloc(sizeof(auction));
	scanf ("%s",str);
	scanf("%d",&unit);
	if (unit<1) {
		printf ("error\n");
		return NULL;
	}
	strcpy(act->name,str);
	act->unit=unit;
	act->auction_num=auction_cnt;
	act->bid_num=0;
	act->bid_arr=NULL;
	auction_cnt++;
	return act;
}
	

int main()
{
	house com;
	auction* act;
	act=(auction*)malloc(sizeof(auction));
	act=init_auction();
	com.active=(auction*)malloc(5*sizeof(auction));
	com.active[0]=act;
	getchar();
}
