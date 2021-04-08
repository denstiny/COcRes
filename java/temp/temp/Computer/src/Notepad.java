public class Notepad  extends computer{
    String Note;
    public Notepad(String Note,String fstab,String cpu,String neicun) {
        super();
        System.out.println("create Notepad ");
        super.SetFstab(fstab);
        super.SetCpu(cpu);
        super.SetNeicun(neicun);
        this.Note = Note;
    }
    @Override
    String Getdetails() {
        return Note+super.Getdetails();
    }
}
