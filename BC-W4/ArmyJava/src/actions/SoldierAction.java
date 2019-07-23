package actions;

import java.util.Random;
import units.Unit;

public class SoldierAction extends Action {
    public SoldierAction(Unit owner) {
        super(owner);
    }

    public void attack(Unit enemy) {
        Random attackRange = new Random();
        int range = this.owner.getDamage() - 5;
        int attackPoints = attackRange.nextInt(10) + range;

        enemy.takeDamage(attackPoints);
    }

    public void counterAttack(Unit enemy) {
        Random cAttackRange = new Random();
        int range = (this.owner.getDamage() / 2) - 5;
        int cAttackPoints = cAttackRange.nextInt(5) + range;

        enemy.takeDamage(cAttackPoints);
    }
}
