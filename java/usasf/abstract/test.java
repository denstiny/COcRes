public class test  {
	public static  void main(String [] args)  {
		dog p = new dog();
		p.setName("旺财");
		p.setAge(20);
		p.setSex("公");
		p.setPrice(12);
		p.setHeight(13);

		System.out.println(p.getName() + p.getAge() + p.getSex() +  p.getHeight());
	}
}
