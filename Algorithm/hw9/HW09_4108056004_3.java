import java.util.ArrayList;

public class HW09_4108056004_3 extends LSD{
    public HW09_4108056004_3(){
    }
    
    static boolean tf;

    public int Distance(int[][] array){
        Gragh graph=new Gragh(array);
        ArrayList<Integer> islandamout = new ArrayList<Integer>();
        int hashlong = graph.hashset.bucket.length;
        
        int islandnum = 0;
        for(int i=0;i<hashlong;i++)
        {
            if(graph.hashset.bucket[i]!=null)
            {
                Element temp=graph.hashset.bucket[i];
                while(temp!=null)
                {
                    if(temp.marked==0)
                    {
                        ChinaQueue queue = new ChinaQueue(10);
                        bfs(temp.key,graph,islandnum,queue,islandamout);
                        islandnum++;
                    }
                    temp=temp.next;
                }
            }
        }
        int maxislandnum=0;
        int maxamout = 0;
        for(int i=0;i<islandamout.size();i++){
            if(islandamout.get(i)>maxamout){
                maxislandnum = i;
                maxamout = islandamout.get(i);
            }
        }
        
        clear(graph,hashlong);
        int min_max = 0;
        tf = false;
        for(int i=0;i<hashlong;i++)
        {
            if(graph.hashset.bucket[i]!=null)
            {
                Element temp=graph.hashset.bucket[i];
                while(temp!=null)
                {
                    if(temp.islandnum == maxislandnum)
                    {
                        ChinaQueue queue = new ChinaQueue(10);
                        min_max = findmin_max(temp.tailvvv,graph,queue);
                        tf = true;
                        break;
                    }
                    temp=temp.next;
                }
                
            }
            if(tf){
                break;
            }
        }
        return min_max;
    }
    
    class Gragh
    {
        public Hash hashset;

        public Gragh(int[][] Edge)
        {
            hashset=new Hash(Edge.length);
            for(int[] v : Edge)
                hashset.put(v[0],v[1]);
        }
        public ArrayList<Integer> getAdj(int v)
        {
            return hashset.get(v);
        }
        public int EdgeOf(int v)
        {
            return hashset.get(v).size();
        }
    }
    class Element
    {
        public int key;
        public int marked;
        public int distto;
        public int islandnum;
        public int tailvvv;
        public ArrayList<Integer> val;
        Element next;
        public Element(int key,ArrayList<Integer> val)
        {
            this.key=key;
            this.val=val;
            this.marked=0;
            next=null;
        }
    }
    class Hash
    {
        public int capacity;
        Element[] bucket;

        public Hash(int cap)
        {
            this.capacity=(1<<(int)(Math.log(cap<<1)/Math.log(2)+1))-1;
            this.bucket=new Element[1+capacity];
        }
        public int hashcode(int num)
        {
            return num&capacity;
        }

        public void put(int v,int u)
        {
            append(v, u);
            append(u, v);
        }
        public void append(int v,int u)
        {
            int hash=hashcode(v);
            for(Element e=bucket[hash];e!=null;e=e.next)
                if(v==e.key)
                {
                    e.val.add(u);
                    return;
                }

            Element newE=new Element(v,new ArrayList<Integer>());
            newE.val.add(u);
            newE.next=bucket[hash];
            bucket[hash]=newE;
        }

        public ArrayList<Integer> get(int v)
        {
            for(Element e=bucket[hashcode(v)];e!=null;e=e.next)
                if(v==e.key)    return  e.val;
            return null;
        }
    }
    class ChinaQueue
    {
        int head;
        int tail;
        int[] array;
        int MAX_QUEUE_SIZE;
        public ChinaQueue(int len)
        {
            array=new int[len];
            MAX_QUEUE_SIZE = len;
            head=tail=0;
        }
        public boolean isEmpty()
        {
            return tail==head;
        }
        public int dequeue()
        {
            if (head == tail){
                System.out.println("Empty");
                return 0; 
            }
            head = (head + 1) % MAX_QUEUE_SIZE;
            return array[head];
        }
        public void enqueue(int v)
        {
            tail = (tail + 1) % MAX_QUEUE_SIZE;
            if (head == tail){
                IwantMore___();
            }
            array[tail] = v;
        }
        public void IwantMore___()
        {
            int[] newarray = new int[array.length*2];
            for(int i=head;i<array.length;i++){
                newarray[i+array.length]=array[i];
            }
            for(int i=0;i<tail;i++){
                newarray[i]=array[i];
            }
            array = newarray;
        }

        
        
    }
    public void bfs(int v, Gragh gragh, int islandnum, ChinaQueue q,ArrayList<Integer> islandamout)
    {
        q.enqueue(v);
        Element temp = gragh.hashset.bucket[v];
        temp.marked = 1;
        temp.islandnum = islandnum;
        int amount = 0;
        int finalvertex=0;
        amount++;
        while(!q.isEmpty()){
            int s = q.dequeue();
            finalvertex = s;
            Element temp1 = gragh.hashset.bucket[s];
            while(temp1!=null)
            {
                if(temp1.key==s)
                    break;
                else{
                    temp1=temp1.next;
                }
            }
            for(int i=0;i<temp1.val.size();i++)
            {
                int qv = temp1.val.get(i);
                Element temp2 = gragh.hashset.bucket[qv];
                if(temp2.marked == 0)
                {
                    q.enqueue(qv);
                    temp2.marked = 1;
                    temp2.islandnum=islandnum;
                    amount++;
                }
            }
        }
        islandamout.add(amount);
        temp.tailvvv=finalvertex;
    }
    public int findmin_max(int v, Gragh gragh, ChinaQueue q)
    {
        q.enqueue(v);
        int max=0;
        Element temp = gragh.hashset.bucket[v];
        temp.marked = 1;
        while(!q.isEmpty()){
            int s = q.dequeue();
            Element temp1 = gragh.hashset.bucket[s];
            while(temp1!=null)
            {
                if(temp1.key==s)
                    break;
                else{
                    temp1=temp1.next;
                }
            }
            for(int i=0;i<temp1.val.size();i++)
            {
                int qv = temp1.val.get(i);
                Element temp2 = gragh.hashset.bucket[qv];
                if(temp2.marked == 0)
                {
                    q.enqueue(qv);
                    temp2.marked = 1;
                    temp2.distto = temp1.distto + 1;
                    if(temp2.distto>max){
                        max=temp2.distto;
                    }
                }
            }
        }
        
        return max;
    }
    public void clear(Gragh gragh, int hashlong){
        for(int i=0;i<hashlong;i++)
        {
            if(gragh.hashset.bucket[i]!=null)
            {
                Element temp=gragh.hashset.bucket[i];
                while(temp!=null)
                {
                    temp.marked=0;
                    temp.distto=0;
                    temp=temp.next;
                }
                
            }
        }
    }
    
}
