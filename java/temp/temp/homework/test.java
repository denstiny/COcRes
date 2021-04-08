public class Test {
	public static void main(String[] args) { 
		 Person[] people = {{"liwei",12},new Person("liqiang",13),new Student("weiqiao",15),new Teacher("wanfei",18),new Teacher("wrold",11)};
		 for(Person temp : people) {
			 System.out.println(temp.name,temp.age);
		 }

	}
	
}
