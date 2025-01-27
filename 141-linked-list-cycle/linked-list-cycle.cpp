class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* marker = new ListNode(0); 
        
        while (head != NULL) {
            if (head->next == marker) { 
                delete marker;          
                return true;
            }

            ListNode* nextNode = head->next; 
            head->next = marker;            
            head = nextNode;               
        }

        delete marker; 
        return false;  
    }
};

