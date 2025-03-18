class Solution {
public:
    ListNode* front;

    bool reverselist(ListNode* head){
        if(head != nullptr){
            if(!reverselist(head->next)){
                return false;
            }
            if(head->val != front->val){
                return false;
            }
            front = front->next;
        }
        return true;
    }

    bool isPalindrome(ListNode* head) {
        front = head;
        return reverselist(head);
    }

public:
    void reorderList(ListNode* head) {
        if (head == nullptr) {
            return;
        }
        ListNode* mid = middleNode(head);
        ListNode* l1 = head;
        ListNode* l2 = mid->next;
        mid->next = nullptr;
        l2 = reverseList(l2);
        mergeList(l1, l2);
    }

    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr != nullptr) {
            ListNode* nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }
        return prev;
    }

    void mergeList(ListNode* l1, ListNode* l2) {
        ListNode* l1_tmp;
        ListNode* l2_tmp;
        while (l1 != nullptr && l2 != nullptr) {
            l1_tmp = l1->next;
            l2_tmp = l2->next;

            l1->next = l2;
            l1 = l1_tmp;

            l2->next = l1;
            l2 = l2_tmp;
        }
    }
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<int> row(matrix.size(),0);
        vector<int> column(matrix[0].size(),0);

        for (int i=0; i< matrix.size(); i++){
            for(int j=0; j< matrix[0].size(); j++){
                if(matrix[i][j]==0){
                    row[i]=1;
                    column[j]=1;
                }
            }
        }

        for( int i=0; i< row.size(); i++){
            for( int j =0; j<column.size(); j++){
                if(row[i]==1||column[j]==1) matrix[i][j]=0;
            }
        }
    }
};