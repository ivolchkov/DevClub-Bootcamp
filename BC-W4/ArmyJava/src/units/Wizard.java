package units;

import abilities.WizardAbility;
import actions.WizardAction;
import magicAbilities.WizardMagicAbility;

public class Wizard extends SpellCaster {
    public Wizard(String name) {
        super(name, 120,150, 20, 0.15, "Wizard", "Alive");
        this.ability = new WizardAbility(this);
        this.action = new WizardAction(this);
        this.magicAbility = new WizardMagicAbility(this);
    }

}
