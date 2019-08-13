package units;

import exceptions.InvalidCastException;
import exceptions.OutOfManaException;
import magicAbilities.MagicAbility;
import spells.*;
import states.MagicState;
import java.util.HashMap;

public abstract class SpellCaster extends Unit {
    protected MagicAbility magicAbility;
    protected HashMap<String, Spell> SpellBook = new HashMap<String, Spell>();

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

    void addSpell(Spell spell) {
        this.SpellBook.put(spell.getSpellName(), spell);
    }

    public void spendMana(int mp) throws OutOfManaException {
        this.state.spendMana(mp);
    }

    public void setAttackSpell(String spellName) {
        this.magicAbility.setAttackSpell(SpellBook.get(spellName));
    }

    public void setHealSpell(String spellName) {
        this.magicAbility.setHealSpell(SpellBook.get(spellName));
    }

    public void cast(Unit enemy) throws OutOfManaException, InvalidCastException {
        this.magicAbility.cast(enemy);
    }

    public void heal(Unit target) throws OutOfManaException, InvalidCastException {
        this.magicAbility.heal(target);
    }

    public void heal() throws OutOfManaException, InvalidCastException {
        this.magicAbility.heal();
    }

    public void createDemon(Demon demon) throws InvalidCastException {
        throw new InvalidCastException();
    }
}
