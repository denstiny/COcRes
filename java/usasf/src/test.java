public class test {
	public static  void main(String[]args) {
		Person people   = new Person("liwei",12);
		Teacher people1 = new Teacher("liqiang",13);
		Teacher people2 = new Teacher("weiqiao",15);
		Student people3 = new Student("wanfei",18);
		Student people4 = new Student("wrold",11);
		Person[] people5 = new Person[]{people1,people2,people3,people4,people};



		System.out.println("排序前");
		for(int i = 0;i < people5.length;i++) {
			System.out.printf("%s \n",people5[i].say());
		}



		for(int i = 0;i < people5.length;i++) {
			people5[i] = (Person)people5[i];
			for(int j = i+1;j < people5.length; j++) {
					if(!(people5[j] instanceof Person) )
							people5[j] = (Person)people5[j];

				if(people5[j].age < people5[i].age)  {
					Person tempPeople = people5[i];
					people5[i] = people5[j];
					people5[j] = tempPeople;
				}

			}
		}


		System.out.println("排序后");
		for(int i = 0;i < people5.length;i++) {
			System.out.printf("%2s \n",people5[i].say());
		}
	}
}

