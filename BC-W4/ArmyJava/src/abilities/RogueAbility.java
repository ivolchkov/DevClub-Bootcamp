package abilities;

import units.Unit;
import exceptions.*;

public class RogueAbility extends Ability {
    public RogueAbility(Unit owner) {
        super(owner);
    }

    public void transform() throws InvalidTransformException {
        throw new InvalidTransformException();
    }

    public void infect(Unit enemy) throws InvalidInfectException {
        throw new InvalidInfectException();
    }
}
