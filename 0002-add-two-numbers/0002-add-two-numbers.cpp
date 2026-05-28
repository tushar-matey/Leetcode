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
    
    void adding(ListNode* l,ListNode* ll,int carry,ListNode* &ans){
        if(l==nullptr && ll==nullptr){
            if(carry==1){
                ans=new ListNode(1);
            }
            return;
        }
        else if(l==nullptr && ll!=nullptr){
            int a=ll->val+carry;
            if(a>=10){
                a-=10;
                ans=new ListNode(a);
                carry=1;
            }
            else{
                ans=new ListNode(a);
                carry=0;
            } 
            adding(l,ll->next,carry,ans->next);
            return;
        }
        else if(l!=nullptr && ll==nullptr){
            int a=l->val+carry;
            if(a>=10){
                a-=10;
                ans=new ListNode(a);
                carry=1;
            }
            else{
                ans=new ListNode(a);
                carry=0;
            }
            adding(l->next,ll,carry,ans->next);
            return;
        }
        else{
            int a=l->val+ll->val+carry;
            if(a>=10){
                a-=10;
                ans=new ListNode(a);
                carry=1;
            }
            else{
                ans=new ListNode(a);
                carry=0;
            } 
        }
        adding(l->next,ll->next,carry,ans->next);
        return;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans;
        adding(l1,l2,0,ans);
        return ans;
    }
};