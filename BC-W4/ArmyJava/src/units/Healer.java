package units;

import abilities.HealerAbility;
import actions.HealerAction;
import magicAbilities.HealerMagicAbility;
import spells.*;

public class Healer extends SpellCaster {
    public Healer(String name) {
        super(name, 110,130, 20, 0.25, "Healer", "Alive");
        this.ability = new HealerAbility(this);
        this.action = new HealerAction(this);
        this.magicAbility = new HealerMagicAbility(this);

        this.addSpell(new AquaSplash(33));
        this.addSpell(new DragonFlame(40));
        this.addSpell(new Fireball(30));
        this.addSpell(new WindVortex(20));
        this.addSpell(new LesserHeal());
        this.addSpell(new GreaterHeal());
        this.addSpell(new KissOfLight());
    }
}
