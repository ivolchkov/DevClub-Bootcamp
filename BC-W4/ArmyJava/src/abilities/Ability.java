package abilities;

import units.Unit;
import exceptions.*;

public abstract class Ability {
    protected Unit owner;

    public Ability(Unit owner) {
        this.owner = owner;
    }

    public abstract void transform() throws InvalidTransformException;
    public abstract void infect(Unit enemy) throws InvalidInfectException;
}
