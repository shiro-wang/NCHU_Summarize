public class HW06_4108056004_1 extends Dessert_Desert{
    public HW06_4108056004_1(){
    }
    
    
    public int[] maxBlocks(int[][] array){
        int num = array.length;
        int[] result = new int[num];
        for(int i=0;i<num;i++){
            int mount = array[i].length;
            int m = 0;
            int[][] maxmin = new int[mount][2];
            maxmin[m][0] = array[i][0]; maxmin[m][1] = array[i][0];

            for(int j=1;j<mount;j++){
                if(array[i][j]<maxmin[m][0]){
                    if(array[i][j]<maxmin[m][1]){
                        maxmin[m][1] = array[i][j];
                    }
                }else{
                    m++;
                    maxmin[m][0] = array[i][j]; maxmin[m][1] = array[i][j];
                }
            }

            for(int j=m;j>0;j--){
                if(maxmin[j][1] < maxmin[j-1][0] || maxmin[j][1] < maxmin[j-1][1]){
                    if(maxmin[j][1] < maxmin[j-1][1]){
                        maxmin[j-1][1] = maxmin[j][1];
                    }
                    m--;
                }
            }
            m++;
            result[i] = m;
        }

        return result;
    }
    
}