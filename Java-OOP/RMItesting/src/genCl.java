import java.rmi.*;
public interface genCl extends Remote {
    public SudokuPuzzle getPuzzle(int K) throws RemoteException;
    public void cleanUp() throws RemoteException;
}
