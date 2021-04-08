public class pc extends computer {
    public pc(String name,String fstab,String cpu,String neicun)  {
        super();
        super.SetFstab(fstab);
        super.SetCpu(cpu);
        super.SetNeicun(neicun);
        this.name = name;
        System.out.println("create pc ");
    }

    public String name;

    @Override
    String Getdetails() {
        return name+super.Getdetails();
    }
}
