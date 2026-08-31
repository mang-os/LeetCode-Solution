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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if (!head || !head->next || !head->next->next) {
            return {-1, -1};
        }
        
        int firstCrit = -1;
        int lastCrit = -1;
        int minDist = INT_MAX;
        
        ListNode* prev = head;
        ListNode* curr = head->next;
        int index = 1;
        
        while (curr->next != nullptr) {
            // Check if current node is a critical point (local maxima or minima)
            if ((curr->val > prev->val && curr->val > curr->next->val) || 
                (curr->val < prev->val && curr->val < curr->next->val)) {
                
                if (firstCrit == -1) {
                    firstCrit = index; // Mark the very first critical point
                } else {
                    // Calculate minimum distance between adjacent critical points
                    minDist = min(minDist, index - lastCrit);
                }
                lastCrit = index; // Update the last seen critical point
            }
            
            // Move to the next set of nodes
            prev = curr;
            curr = curr->next;
            index++;
        }
        
        // If we found fewer than 2 critical points
        if (minDist == INT_MAX) {
            return {-1, -1};
        }
        
        // Max distance is always between the first and last critical points found
        return {minDist, lastCrit - firstCrit};
    }
};