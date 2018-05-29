package my;

public class Hero implements Comparable<Hero> {
	String key = "attack";
	int hp;
	int mana;
	int level;
	int attack;
	String name;
	int stars;
	int price;
	Hero(){
		
	}
	Hero(String name, int hp, int mana, int level, int attack, int stars, int price){
		this.name = name;
		this.hp = hp;
		this.mana = mana;
		this.level = level;
		this.attack = attack;
		this.stars = stars;
		this.price = price;
	}
	@Override
	public int compareTo(Hero arg0) {
		switch(this.key){
		case "name":
			return this.name.compareTo(arg0.name);
		case "hp":
			return this.hp - arg0.hp;
		case "mana":
			return this.mana - arg0.mana;
		case "level":
			return this.level - arg0.level;
		case "attack":
			return this.attack - arg0.attack;
		case "stars":
			return this.stars - arg0.stars;
		case "price":
			return this.price - arg0.price;
		default:
			return 0;
		}
	}
	
	
}
