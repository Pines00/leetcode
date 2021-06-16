####  Add  Two Numbers[原题地址](https://leetcode-cn.com/problems/add-two-numbers/submissions/)

You  are  given  two  linked  lists  representing  two  non-negative  numbers.   The  digits  are  stored  in  reverse order and  each  of  their nodes  contain  a  single  digit.  Add  the  two numbers and return it as a linked list.

Input:  (2 -> 4 -> 3) + (5 -> 6 -> 4)

Output:  7 -> 0 -> 8

1.菜鸟题解

​	设置进位标志，进位整除10，余下来的值mod（10）。设置指针p与q分别指向l1，l2。当q与p都不为空时，则进行普通加减，该进位进位。当有个为空时停下。然后接着非空的链表开始进行相加。

菜鸟理解就是一点一点加，先加位置相等的点，余下来的点再继续加。

```
 ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *p =l1,*q= l2;
        ListNode dunmmy(-1);
        ListNode *prev = &dunmmy;
        int carry=0;
        int value = 0;
        while(p&&q){
            value =(p->val+q->val+carry)%10;
            carry = (p->val+q->val+carry)/10;
            prev->next = new ListNode(value);
            prev = prev->next;
            p =p->next;
            q= q->next;
        }
        while(p){//当p不为空时候，加p的节点
            value = (p->val+carry)%10;
            carry = (p->val+carry)/10;
            prev->next = new ListNode(value);
             prev = prev->next;
            p=p->next;
        }
        while(q){//当q不为空时候，加q的节点
            value = (q->val+carry)%10;
            carry = (q->val+carry)/10;
            prev->next = new ListNode(value);
             prev = prev->next;
            q=q->next;
        }
        if(carry>0){//还要判断最后一位是否有进位，如果有就要新建一个节点
            prev->next = new ListNode(carry);
        }
        return dunmmy.next;
    }
```

2.高手理解

一起判断，当他们两个链表中有一个为空的时候，将空节点的值设置为0，进行相加，就不用了接着判断了，具体表现为 `int ai = pa == nullptr ? 0 : pa->val;`如果为空指针，将值设为0，如果不是空指针，就下一个。方便了很多。

```c++
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *p =l1,*q= l2;
        ListNode dunmmy(-1);
        ListNode *prev = &dunmmy;
        int carry=0;
        int value = 0;
        int pa=0,pb=0;
        while(p!=nullptr||q!=nullptr){
            pa = (p==nullptr? 0:p->val);
            pb = (q==nullptr? 0:q->val);
            value =(pa+pb+carry)%10;
            carry = (pa+pb+carry)/10;
            prev->next = new ListNode(value);
            p = (p == nullptr ? nullptr : p->next);
            q = (q == nullptr ? nullptr : q->next);
            prev = prev->next;
        }
        if(carry>0){
            prev->next = new ListNode(carry);
        }
        return dunmmy.next;
    }
};
```

