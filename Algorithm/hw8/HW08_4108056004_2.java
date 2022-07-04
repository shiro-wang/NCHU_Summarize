public class HW08_4108056004_2 extends Buy_Phone_v2{
    public HW08_4108056004_2(){
    }
    public static void main(String args[]){
        int [][] array = {{8,7,7,4,2,1},{2,4,4,6,2,1},{4,0,5,1,3,2},{5,2,4,3,7,3},{7,5,6,9,8,9},{4,1,7,10,1,4},{4,1,7,10,2,3}};
        HW08_4108056004_2 test = new HW08_4108056004_2();
        int[][] ans = test.bestPhone(array);
        for(int i=0;i<ans.length;i++){
            System.out.println(ans[i][0]+","+ans[i][1]+","+ans[i][2]+","+ans[i][3]+","+ans[i][4]+","+ans[i][5]);
        } 
    }
    static int [][] anstemp = new int [1000][6];
    static int [][] aux = new int[1000][6];
    static int [] max = new int [6];
    static boolean tf;
    public int[][] bestPhone(int[][] array){
        int num = array.length;
        int ansnum = 1;
        merge(array);
        anstemp[0] = array[0];
        for(int i=0;i<6;i++){
            max[i] = anstemp[0][i];
        }
        for(int i=1;i<num;i++){
            tf = false;
            for(int j=1;j<6;j++){
                if(array[i][j]>max[j]){
                    tf = true;
                    max[j] = array[i][j];
                }
            }

            if(tf){
                anstemp[ansnum++] = array[i];
            }
        }

        
        int [][] result = new int[ansnum][2];
        for(int i=0;i<ansnum;i++){
            result[ansnum-i-1] = anstemp[i];
        }

        return result;
    }

    public static void merge(int[][] number){
        for(int i=0;i<number.length;i++){
            aux[i] = number[i];
        }
        sort(number, aux, 0, number.length-1);
    }
    
    private static void sort(int[][] number, int[][] aux, int lo, int hi) {
        if(hi<=lo) return;
        
        int mid = lo + (hi - lo)/2;
        sort(number,aux,lo,mid);
        sort(number,aux,mid+1,hi);
        mergesort(number,aux,lo,mid,hi);
    }

    private static void mergesort(int number[][],int[][] aux, int lo,int mid, int hi) {  
        int i = lo;
        int j = mid+1;
        for(int k=lo; k<=hi; k++){
            if(i>mid) number[k] = aux[j++];
            else if(j>hi) number[k] = aux[i++];
            else if(aux[j][0] == aux[i][0]){
                int l = 1;
                while(aux[j][l] == aux[i][l] && l<5) l++;
                if(aux[j][l]>aux[i][l]) number[k] = aux[j++];
                else number[k] = aux[i++];
            }
            else if(aux[j][0]>aux[i][0]) number[k] = aux[j++];
            else number[k] = aux[i++];
            
        }
        for(i=lo;i<=hi;i++){
            aux[i]=number[i];
        }
    } 
}