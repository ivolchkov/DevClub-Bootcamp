package abilities;

import units.*;
import actions.WerewolfAction;
import states.State;
import exceptions.*;

public class WerewolfAbility extends Ability {
    public WerewolfAbility(Unit owner) {
        super(owner);
    }

    public void transform() throws InvalidTransformException {
        if ( owner.getHitPointsLimit() == 150 ) {
            int newHitPoints = owner.getHitPoints() * 2;
            int newHitPointsLimit = owner.getHitPointsLimit() * 2;
            int newDamage = owner.getDamage() * 2;
            double newMagicResist = owner.getMagicResist() / 4;

            owner.setState(new State(owner.getName(), newHitPoints, newDamage,newMagicResist, owner.getTitle(),owner.getType()));
            owner.setHitPointsLimit(newHitPointsLimit);
        } else {
            int newHitPoints = owner.getHitPoints() / 2;
            int newHitPointsLimit = owner.getHitPointsLimit() / 2;
            int newDamage = owner.getDamage() / 2;
            double newMagicResist = owner.getMagicResist() * 4;

            owner.setState(new State(owner.getName(), newHitPoints, newDamage, newMagicResist, owner.getTitle(),owner.getType()));
            owner.setHitPointsLimit(newHitPointsLimit);
        }
    }

    public void infect(Unit enemy) throws InvalidInfectException {
        if ( !(enemy.getAbility() instanceof VampireAbility) && !(enemy.getAbility() instanceof WerewolfAbility) ) {
            String title  = enemy.getTitle() + "(turned)";

            enemy.setAbility(new WerewolfAbility(enemy));
            enemy.setAction(new WerewolfAction(enemy));
            enemy.setState(new State(enemy.getName(), owner.getHitPointsLimit(), owner.getDamage(), owner.getMagicResist(), title, owner.getType()));
        } else {
            throw new InvalidInfectException();
        }
    }
}
