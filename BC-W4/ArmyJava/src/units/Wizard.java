package units;

import abilities.WizardAbility;
import actions.WizardAction;
import magicAbilities.WizardMagicAbility;
import spells.*;

public class Wizard extends SpellCaster {
    public Wizard(String name) {
        super(name, 120,150, 20, 0.15, "Wizard", "Alive");
        this.ability = new WizardAbility(this);
        this.action = new WizardAction(this);
        this.magicAbility = new WizardMagicAbility(this);

        this.addSpell(new AquaSplash());
        this.addSpell(new DragonFlame());
        this.addSpell(new Fireball());
        this.addSpell(new WindVortex());
        this.addSpell(new LesserHeal(20));
        this.addSpell(new GreaterHeal(45));
        this.addSpell(new KissOfLight(60));
    }

}
