
class sudoku_solver
{
    private:
        sudoku* x;


        bool solveMain(int i, int j)
        {

            if(i==9)
                return 1;
            if(j==9)
                return solveMain(i+1, 0);
           
            if(x->get(i, j))
                return solveMain(i, j+1);

            for(int k=1; k<=9; k++)
            {
                if(x->set(i, j, k))
                {
                    bool ret = solveMain(i, j+1);
                    if(ret)
                        return 1;
                }
                x->clear(i, j);
            }
          
            return 0;
        }


    public:
        sudoku_solver(sudoku* x)
        {
            this->x = x; 
        }


        void solve()
        {
            solveMain(0, 0);
        }
};
