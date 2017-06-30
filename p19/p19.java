/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution2 {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode p=head,q=head;
        for(int i=0;i<n;i++)
            if(q!=null) q=q.next;
            
        if(q==null)
        {
            head=head.next;
            return head;
        }
        
        while(true)
        {
            if(q.next==null)
            {
                if(p.next!=null)
                    p.next=p.next.next;
                break;
            }
            p=p.next;
            q=q.next;
        }

        return head;
    }
}

public class Solution1 {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode p=head,q;
        int t=0,idx=0;
        while(p!=null)
        {
    		t++;
        	p=p.next;
        }
        
       	t=t-n+1;
       	if(t<=0) return head;
       	if(t==1) { head=head.next; return head;}

        p=q=head;
        while(p!=null)
        {
        	idx++;
        	if(idx==t)
        	{
        	    q.next=p.next;
        		break;
        	}
        	q=p;
        	p=p.next;
       	}

        return head;
    }
}