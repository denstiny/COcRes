public class computer {
    public computer() {
        System.out.println("create computer");
        fstab = "";
        cpu  = "";
        neicun  = "";
    }
    private String fstab;
    private String cpu;
    private String neicun;
    void SetFstab(String fstab) {
        this.fstab = fstab;
    }
    void SetCpu(String cpu) {
        this.cpu = cpu;
    }
    void SetNeicun(String neicun) {
        this.neicun = neicun;
    }

    String Getdetails() {
        return fstab+cpu+neicun;
    }
    String GetCpu() {return this.cpu;};
    String GetNeicun() {return this.neicun;};
    String GetFstab() {return this.fstab;};
}
