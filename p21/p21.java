class ListNode {
    int val;
    ListNode next;
    ListNode(int x) { val = x; }
}

public class p21 {
    public static ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        ListNode ans = new ListNode(0);
        ListNode p=ans,p1=l1,p2=l2;

        while(p1!=null && p2!=null)
        {
            if(p1.val<=p2.val)
            {
            	p.next=p1;
            	p1=p1.next;
            }
            else
            {
            	p.next=p2;
            	p2=p2.next;
            }
            p=p.next;
        }
        if(p1!=null) p.next=p1;
        else
        if(p2!=null) p.next=p2;

        ans=ans.next;
        return ans;
    }

    public static void main(String[] args)
    {
    	ListNode l1 = new ListNode(2);
    	l1.next = new ListNode(6);
    	l1.next.next = new ListNode(9);

    	ListNode l2 = new ListNode(1);
    	l2.next = new ListNode(2);
    	l2.next.next = new ListNode(3);

    	ListNode a = mergeTwoLists(l1,l2);

    	while(a!=null)
    	{
    		System.out.println(a.val);
    		a=a.next;
    	}
    }
}