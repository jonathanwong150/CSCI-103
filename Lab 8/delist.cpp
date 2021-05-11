#include "delist.h"
#include <iostream>
#include <cstdlib>

using namespace std;

DEList::DEList(){
  head=NULL;
  tail=NULL;
  num=0;
}
DEList::~DEList(){
  DEItem* track=head;
  while(track!=tail){
    track=track->next;
    delete head;
    head=track;
  }
  delete track;
}
bool DEList::empty(){
  if(num==0){
    return 1;
  }
  return 0;
}
int DEList::size(){
  return num;
}
int DEList::front(){
  if(empty()){
    return -1;
  }else{
    return head->val;
  }
}
int DEList::back(){
  if(empty()){
    return -1;
  }else{
    return tail->val;
  }
}
void DEList::push_front(int new_val){
  if(empty()){
		DEItem* item = new DEItem;
		item->prev=NULL;
		item->val=new_val;
		item->next=NULL;
		head=item;
		tail=item;
	}
	else{
		DEItem*item = new DEItem;
		item->next=head;
		item->val=new_val;
		item->prev=NULL;
		head->prev=item;
		head=item;
	}
  num++;
}
void DEList::push_back(int new_val){
  	if(empty()){
		DEItem*temp = new DEItem;
		temp->prev=NULL;
		temp->val=new_val; 
		temp->next=NULL;
		head = temp;
		tail = temp;
	}
	else{
		DEItem*temp = new DEItem;
		temp->prev=tail;
		temp->val=new_val;
		temp->next=NULL;
		tail->next=temp;
		tail=temp;
	}
  num++;
}
void DEList::pop_front(){
  if(!empty()){
    DEItem* item = head;
    head=item->next;
    delete item;
    num--;
  }
}
void DEList::pop_back(){
  if(!empty()){
    DEItem* item = tail;
    tail=item->prev;
    delete item;
    num--;
  }
}
