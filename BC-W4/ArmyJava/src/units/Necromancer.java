package units;

import abilities.NecromancerAbility;
import actions.NecromancerAction;
import exceptions.UnitIsDead;
import interfaces.Observer;
import magicAbilities.NecromancerMagicAbility;
import spells.*;

public class Necromancer extends SpellCaster implements Observer {
    public Necromancer(String name) {
        super(name, 130,110, 20, 0.25, "Necromancer", "Undead");
        this.ability = new NecromancerAbility(this);
        this.action = new NecromancerAction(this);
        this.magicAbility = new NecromancerMagicAbility(this);

        this.addSpell(new AquaSplash());
        this.addSpell(new DragonFlame());
        this.addSpell(new Fireball());
        this.addSpell(new WindVortex());
        this.addSpell(new LesserHeal(20));
        this.addSpell(new GreaterHeal(45));
        this.addSpell(new KissOfLight(60));

    }

    public void update(Unit enemy) throws UnitIsDead {
        this.addHitPoints(enemy.getHitPointsLimit() / 4);
    }
}
