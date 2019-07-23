public class GunMain {
    public static void main(String[] args) throws CloneNotSupportedException, OutOfRoundsException, NotReadyException {
        Gun beretta = new Gun("Beretta1", 10);
        Gun gun2 = beretta.clone();
        Gun gun = new Gun();
                
        System.out.println("Gun:" + beretta);
        System.out.println("Gun2:" + gun);
        
        beretta.reload();
        beretta.prepare();
        beretta.shoot();
        
        System.out.println("Gun:" + beretta);
        System.out.println("Gun2:" + gun);
        System.out.println("Atributes:" + beretta.getAmount() + " " + beretta.getCapacity() + " " + beretta.getModel() + " " + beretta.getTotalShots());
    }
}
