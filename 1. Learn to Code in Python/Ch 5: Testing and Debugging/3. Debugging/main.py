def take_magic_damage(health, resist, amp, spell_power):
    return health - spell_power * amp + resist

