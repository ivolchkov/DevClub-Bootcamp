package units;

import abilities.PriestAbility;
import actions.PriestAction;
import magicAbilities.PriestMagicAbility;
import spells.*;

public class Priest extends SpellCaster {
    public Priest(String name) {
        super(name, 100,140, 15, 0.2, "Priest", "Alive");
        this.ability = new PriestAbility(this);
        this.action = new PriestAction(this);
        this.magicAbility = new PriestMagicAbility(this);

        this.addSpell(new AquaSplash(33));
        this.addSpell(new DragonFlame(40));
        this.addSpell(new Fireball(30));
        this.addSpell(new WindVortex(20));
        this.addSpell(new LesserHeal());
        this.addSpell(new GreaterHeal());
        this.addSpell(new KissOfLight());
    }
}
