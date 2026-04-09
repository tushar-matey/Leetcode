/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void insert(ListNode* &head,int val){
        ListNode* n=new ListNode(val);
        if(head==nullptr){
            head=n;
            return;
        }
        ListNode* temp =head;
        while(temp->next!=nullptr){
            temp=temp->next;
        }
        temp->next=n;
    }

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head=nullptr;
        if(list1==nullptr && list2==nullptr){
            return head;
        }
        if(list1==nullptr){
            return list2;
        }
        if(list2==nullptr){
            return list1;
        }
        while((list1 != nullptr)||(list2 != nullptr)){
            if((list1 != nullptr)&&(list2 != nullptr)){
                if(list1->val<=list2->val){
                    insert(head,list1->val);
                    list1=list1->next;
                }
                else{
                    insert(head,list2->val);
                    list2=list2->next;
                }
            } 
            else if(list1!=nullptr){
                insert(head,list1->val);
                list1=list1->next;
            }
            else if(list2!=nullptr){
                insert(head,list2->val);
                list2=list2->next;
            }   
        }       
        return head;
    }
};