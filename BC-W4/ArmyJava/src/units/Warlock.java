package units;

import abilities.WarlockAbility;
import actions.WarlockAction;
import exceptions.DontTouchYourMasterException;
import exceptions.InvalidCastException;
import magicAbilities.WarlockMagicAbility;
import spells.*;
import units.Demon;

import java.util.ArrayList;
import java.util.List;

public class Warlock extends SpellCaster {
    private List<Demon> demonList = new ArrayList<Demon>();

    public Warlock(String name) {
        super(name, 120,120, 20, 0.2, "Warlock", "Alive");
        this.ability = new WarlockAbility(this);
        this.action = new WarlockAction(this);
        this.magicAbility = new WarlockMagicAbility(this);

        this.addSpell(new AquaSplash());
        this.addSpell(new DragonFlame());
        this.addSpell(new Fireball());
        this.addSpell(new WindVortex());
        this.addSpell(new LesserHeal(20));
        this.addSpell(new GreaterHeal(45));
        this.addSpell(new KissOfLight(60));
        this.addSpell(new DemonsCall());

    }

    public void createDemon(Demon demon) throws InvalidCastException {
        demonList.add(demon);
    }

    public void demonAttack(Unit enemy) throws DontTouchYourMasterException {
        if ( enemy.getName().equals(this.getName()) ) {
            throw new DontTouchYourMasterException();
        }

        for (Demon d: this.demonList
             ) {
            d.attack(enemy);
        }
    }

    public String toString() {
        return "Unit: " + this.state + "\n" + "With " + this.demonList.size() + " demons";
    }
}
