import abilities.*;
import spells.AquaSplash;
import units.*;
import actions.*;
import states.*;
import exceptions.*;

public class Main {
    public static void main(String[] args) throws Throwable {
        Soldier knight = new Soldier("Borys");
        Soldier arthas = new Soldier("Arthas");

        System.out.println(knight);
        System.out.println(arthas);

        knight.attack(arthas);


        System.out.println("----------------------------------");

        System.out.println(knight);
        System.out.println(arthas);

        System.out.println("----------------------------------");
        Rogue valyra = new Rogue("Valyria");

        System.out.println(valyra);

        valyra.attack(knight);

        System.out.println(knight);
        System.out.println(valyra);
        System.out.println("----------------------------------");

        Vampire vlad = new Vampire("Vlad");
        Werewolf lucan = new Werewolf("Lucan");

        System.out.println(vlad);
        System.out.println(lucan);
        System.out.println("----------------------------------");

        vlad.infect(knight);

        System.out.println(knight);

        lucan.infect(valyra);
        System.out.println(valyra);

        knight.attack(arthas);
        System.out.println(arthas);

        System.out.println("----------------------------------");
        Wizard sorc = new Wizard("Sorcerer");

        System.out.println(sorc);

        sorc.showAllSpells();

        sorc.setAttackSpell("AquaSplash");
        System.out.println(knight);
        sorc.cast(knight);
        System.out.println(knight);

    }
}
