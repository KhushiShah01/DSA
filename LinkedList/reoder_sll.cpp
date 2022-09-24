#include<iostream>
#include<stack>

using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

void reorderList(ListNode* head) {
        if (head == NULL || head->next == NULL || !head->next->next) {
          return;
        }        
        stack<ListNode*> st;
        ListNode* temp=head;
        int size = 0;
        while(temp!=NULL) {
            st.push(temp); 
            size++;
            temp=temp->next;
        }
        ListNode* s, *list = head; 
        for(int i=0;i<size/2;i++){
            ListNode* s = st.top();
            st.pop();
            s->next = list->next;
            list->next = s;
            list = list->next->next;
        }
        list->next = NULL;
        
}