class test1{
    public static void transport(int [][] matrix, int [][] matrixT){
        
    }

    public static void main(String[] args) {
        int [][] matrix = {{1,2,3},{4,5,6}};
        int [][] matrixT = new int[3][2];

        for(int i = 0; i < matrix.length; i++){
            for(int j = 0; j < matrix[i].length; j++)
                System.out.print(matrix[i][j] + " ");
            System.out.println();
        }
        
        System.out.println("----------------------------------------------");
        transport(matrix, matrixT);

        for(int i = 0; i < matrixT.length; i++){
            for(int j = 0; j < matrixT[i].length; j++)
                System.out.print(matrixT[i][j] + " ");
            System.out.println();
        }
    }
}