package units;

import states.MagicState;
import java.util.HashMap;

public abstract class SpellCaster extends Unit {
    protected MagicAbility magicAbility;
    protected HashMap<String, Spell> SpellBook;

    public SpellCaster(String name, int hp, int mp, int dmg, double magicResist, String title, String type) {
        super(name, hp, dmg, magicResist, title, type);
        this.magicAbility = new MagicAbility(this);
        this.state = new MagicState(name, hp, mp, dmg, magicResist, title, type);
    }

    public void showAllSpells() {
        System.out.println("This magician has next spells: ");
        for (String s:
             SpellBook.keySet()) {
            System.out.println(s);
        }
    }

    public void setAttackSpell(Spell spell) {

    }

}
